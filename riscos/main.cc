/*
 * \brief  RISCOS on second core
 * \author Michael Grunditz
 * \date   2024-08-15
 *
 */

/*
 * Copyright (C) 2012-2017 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#include <base/component.h>
#include <base/log.h>
#include <base/thread.h>
#include <log_session/connection.h>
#include <base/attached_io_mem_dataspace.h>
#include <terminal_session/connection.h>
#include <libc/component.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <sys/select.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "riscos.h"
#include "muinc.h"
#define STDIN 0

#include <gui_session/connection.h>
#include <os/pixel_rgb888.h>
#include <input/event.h>
#include <blit/blit.h>
#include "scan_code_set_ro.h"
int oldx=0;//640/2;
int oldy=0;

static  Genode::addr_t _mubuf;
static  Genode::addr_t mbufb;
static  Genode::addr_t _statusbuf;

Gui::Session::View_handle *g_handle;

static Gui::Connection *_gui;//   { env, "unicorn" };
typedef Genode::Pixel_rgb888 PT;
	static PT *_src;
	static PT *_dst;
int copycount=0;
#if 1
static void my_copy(volatile unsigned char *dst, volatile unsigned char *src, int sz)
{
    if (sz & 63) {
        sz = (sz & -64) + 64;
    }
    asm volatile (
		    "NEONCopyPLD: \n"
"sub %[dst], %[dst], #64 \n"
"1: \n"
"ldnp q0, q1, [%[src]] \n"
"ldnp q2, q3, [%[src], #32] \n"
"add %[dst], %[dst], #64 \n"
"subs %[sz], %[sz], #64 \n"
"add %[src], %[src], #64 \n"
"stnp q0, q1, [%[dst]] \n"
"stnp q2, q3, [%[dst], #32] \n"
"b.gt 1b \n" : [dst]"+r"(dst), [src]"+r"(src), [sz]"+r"(sz) : : "d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7", "cc", "memory");
}
#endif


struct Inp_thread : Genode::Thread
{
        int _thread_id;
        Inp_thread(Genode::Env &env, int thread_id)
        : Genode::Thread(env, "test_thread", 16*1024),
          _thread_id(thread_id)
        {
                start();
        }
     
        void entry() override
        {
	struct timespec tv;
	*((uint32_t*)((char*)_mubuf+0x8))=0;
        int rx = 0;
        int ry = 0;
	uint32_t coords=0;
		while(1) {
	tv.tv_nsec=907000;
	tv.tv_sec=0;

	_gui->input()->for_each_event([&] (Input::Event const &ev) {
     
coords=0;
	ev.handle_press([&] (Input::Keycode key, Genode::Codepoint) {
	if (key==Input::BTN_LEFT||key==0x112)
	{
	Genode::log("mouse press");  
*((uint32_t*)((char*)_mubuf+0xc))=coords;

	if (key==0x112)
	{
	Genode::log("mouse button middle");
 	*((uint32_t*)((char*)_mubuf+0x8))=400;   
	}
	else {
 	*((uint32_t*)((char*)_mubuf+0x8))=100;   
	}
	*((uint32_t*)((char*)_mubuf+0x24))|=(0x1U<<17);
	*((uint32_t*)((char*)mbufb+0x24))|=(1U<<17);//0xe0000;
 
       while(*((uint32_t*)((char*)mbufb+0x20))& 0x20000000)
	{    
       
	
	if (key==0x112)
	*((uint32_t*)((char*)_mubuf+0x8))=400;   
	else
	*((uint32_t*)((char*)_mubuf+0x8))=100;   
	
}
	
                    
	tv.tv_nsec=1000;
	Libc::with_libc([&] () { nanosleep(&tv, (struct timespec *)NULL);}); 
	
	}
	else
	{
      if (scan_code_set_ro[key][1]!=1000 && key!=0x112)
      {
	
	if (key==0x112)
	{
		
	 volatile uint32_t menupress=400;
	  *((uint32_t*)((char*)_mubuf+0xc))=coords;
	  *((uint32_t*)((volatile char*)_mubuf+0x8))=menupress;
	}
	else
	{
	  *((uint32_t*)((char*)_mubuf+0x8))=scan_code_set_ro[key][1];
	}
	  *((uint32_t*)((char*)_mubuf+0x24))|=(0x1U<<17);
        *((uint32_t*)((char*)mbufb+0x24))|=(1U<<17);//0xe0000;

       while(*((uint32_t*)((char*)mbufb+0x20))& 0x20000000)
        {

        
        *((uint32_t*)((char*)_mubuf+0x8))=scan_code_set_ro[key][1];
        
}
       
        tv.tv_nsec=1000;
        Libc::with_libc([&] () { nanosleep(&tv, (struct timespec *)NULL);});
       
        }




      }	      

	
                  
                });
	ev.handle_release([&] (Input::Keycode key) {
	
	if (key==Input::BTN_LEFT||key==0x112)
	{
#if 1
	if (key==0x112)
	{
	
	*((uint32_t*)((char*)_mubuf+0x8))=500;   
	}
	else
	{
	*((uint32_t*)((char*)_mubuf+0x8))=200;   
	}
*((uint32_t*)((char*)_mubuf+0xc))=coords;
	*((uint32_t*)((char*)_mubuf+0x24))|=(0x1U<<17);
	*((uint32_t*)((char*)mbufb+0x24))|=(1U<<17);//0xe0000;
     
while(*((uint32_t*)((char*)mbufb+0x20))& 0x20000000)
 	{    
 
	
	 tv.tv_nsec=1000;
	Libc::with_libc([&] () { nanosleep(&tv, (struct timespec *)NULL);}); 

	if (key==0x112)
  	*((uint32_t*)((volatile char*)_mubuf+0x8))=500;   
	else
  	*((uint32_t*)((volatile char*)_mubuf+0x8))=200;   

#endif	               		
	
	}
 
	
} else
       if (scan_code_set_ro[key][1]!=1000 && key!=0x112)
      {     
	
	volatile uint32_t menurel=500;
	if (key==0x112)
	{
		
	*((uint32_t*)((char*)_mubuf+0xc))=coords;
	  *((uint32_t*)((volatile char*)_mubuf+0x8))=menurel;
	}
	else
	{
	  *((uint32_t*)((char*)_mubuf+0x8))=scan_code_set_ro[key][1]+1000;
	}
	  *((uint32_t*)((char*)_mubuf+0x24))|=(0x1U<<17);
        *((uint32_t*)((char*)mbufb+0x24))|=(1U<<17);//0xe0000;

       while(*((uint32_t*)((char*)mbufb+0x20))& 0x20000000)
        {

        
        *((uint32_t*)((char*)_mubuf+0x8))=scan_code_set_ro[key][1]+1000;
        
}
        

        tv.tv_nsec=1000;
        Libc::with_libc([&] () { nanosleep(&tv, (struct timespec *)NULL);});
       
        }

 


			});
   
                         ev.handle_absolute_motion([&] (int x, int y) {
			  static int ox = 0, oy = 0;
                rx = x - ox; ry = oy - y;
                ox = x; oy = y;
	
	       rx=(x-100)*2;
		ry=(480-(y-100))*2;	       
			});
  
 	coords=0;
	coords=ry<<16;
			coords|=rx;		
		
                          
                });

*((uint32_t*)((char*)_mubuf+0xc))=coords;
	tv.tv_nsec=907000;
	Libc::with_libc([&] () { nanosleep(&tv, (struct timespec *)NULL);}); 
				
	}
	}
};
struct Test_thread : Genode::Thread
{
        int _thread_id;
        Test_thread(Genode::Env &env, int thread_id)
        : Genode::Thread(env, "test_thread", 16*1024),
          _thread_id(thread_id)
        {
                start();
        }

        void entry() override
        {
	struct timespec first  {0,0};
	uint64_t llTime, llFrameDelta, llTargetTime, llOldTime;
	int64_t ns,nsret;
        Libc::with_libc([&] () { clock_gettime(CLOCK_MONOTONIC, &first); });
	llFrameDelta = 1000000000 / 60; 
	nsret=first.tv_nsec;
	llTargetTime = llOldTime = nsret + llFrameDelta; // end of frame time
	

while(1) {
	struct timespec tv;
	struct timespec last  {0,0};
		first.tv_nsec=5;
	first.tv_sec=0;
	last.tv_nsec=0;
	last.tv_sec=0;
        Libc::with_libc([&] () { clock_gettime(CLOCK_MONOTONIC, &first); });
	nsret=first.tv_nsec + (first.tv_sec * 1000000000LL);
	

	tv.tv_sec=0;
	tv.tv_nsec=10;
	my_copy((unsigned char*)_dst,(unsigned char*)_src,640*480*4);
	
         _gui->framebuffer()->refresh(0,0,639,479);
    
        Libc::with_libc([&] () { clock_gettime(CLOCK_MONOTONIC, &last); });
	llTime=last.tv_nsec + (last.tv_sec * 1000000000LL);
		ns = llFrameDelta - (llTime-nsret); 

if (ns < 0) 
		{
	
			Genode::log("nslag ",Genode::Hex(llTime-nsret));

			tv.tv_nsec=0x582e38;
		Libc::with_libc([&] () { nanosleep(&tv, (struct timespec *)NULL);}); 

			Genode::log("crap");
		}
else
{

tv.tv_nsec = ns;

		Libc::with_libc([&] () { nanosleep(&tv, (struct timespec *)NULL);}); 


}
llTargetTime += llFrameDelta;



}

		}
};

__attribute__ ((noinline)) void  Libc::Component::construct(Libc::Env &env)
{
	       using Command     = Gui::Session::Command;



        enum { CONFIG_ALPHA = false };
        static Gui::Connection   gui   { env, "risc_os" };//unicorn" };
        int const scr_w=640;
	int const scr_h=480;
	Framebuffer::Mode const mode { .area = { scr_w,scr_h } };
        gui.buffer(mode, false);
        
Genode::Attached_io_mem_dataspace _hwds(env, 0xA0000100, 640*480*4,true);
   PT * hwbuffer=_hwds.local_addr<PT>();
        Genode::Attached_dataspace fb_ds(
                env.rm(), gui.framebuffer()->dataspace());
        PT * swbuffer = fb_ds.local_addr<PT>();
	_dst=swbuffer;
	_src=hwbuffer;
        _gui=&gui;

	memset(hwbuffer,0,640*480*4);
   

        if (!scr_w || !scr_h) {
                return;
        }
	

                        using namespace Gui;

                        Gui::Session::View_handle _handle;
			g_handle = &_handle;
                        
                        _handle = gui.create_view();


                        Gui::Rect rect(Gui::Point(100,100), Gui::Area(scr_w,scr_h));
                        gui.enqueue<Command::Geometry>(_handle, rect);
                        gui.enqueue<Command::To_front>(_handle, Gui::Session::View_handle());
                        gui.enqueue<Command::Title>(_handle, "riscosfb");
                        gui.execute();
                        
	
	Terminal::Connection       _terminal(env,"");
	struct timespec tv;
	tv.tv_sec=0;
	tv.tv_nsec=10000;
	using namespace Genode;
	   
	 Genode::Attached_io_mem_dataspace _ds(env, 0x80010000, riscos25_len,true);//, _base(base), _size(size),
	 Genode::Attached_io_mem_dataspace _mu_addr(env, 0xA0000100+(640*480*4)+8, 4,true);//, _base(base), _size(size),
	
	 Genode::Attached_io_mem_dataspace _ds_mu1(env, 0x30ab0000, 40,true);
	 Genode::Attached_io_mem_dataspace _ds_mu1b(env, 0x30aa0000, 40,true);
  									     _ds_mu=&_ds_mu1;
        
	Genode::addr_t mubuf =  (Genode::addr_t)_ds_mu->local_addr<void>();
	Genode::addr_t mubufB =  (Genode::addr_t)_ds_mu1b.local_addr<void>();
	Genode::addr_t muaddrbuf =  (Genode::addr_t)_mu_addr.local_addr<void>();
	_mubuf=mubuf;       
      	 Test_thread test_thread(env, 1);
      	 Inp_thread inp_thread(env, 1);
                 
(*((uint32_t*)((char*)mubufB+0x24)))=(0xfU<<28);
	mbufb=mubufB;					
	Genode::log("From riscos mubuf: ",Genode::Hex(mubuf));
	Genode::log("From riscos readback mubuf: ",Genode::Hex(*((uint32_t*)muaddrbuf)));
	volatile Genode::addr_t statusbuf =mubuf+0x20;
	_statusbuf=statusbuf;
	Genode::addr_t resetbuf =mubuf+0x24;
	*((int*)resetbuf)=0xf0000000;//1U<<23; 
	volatile Genode::addr_t recbuf =mubuf+0x10;
  
	 log("logic addr: ",Hex((Genode::addr_t)_ds.local_addr<void>()));
	 memcpy((unsigned char*)_ds.local_addr<void*>(),(unsigned char*)riscos25,riscos25_len);        

          	        
	asm volatile (
			"mov x0,#555 \n\t"
			"svc #0 \n\t"
						);
	volatile int strcount=0;
	while (1)
	{
       
       if ((int)(*((int*)(statusbuf))) & (1<<27))
       {
	 
#if 1
    
        int a = int(*((int*)(recbuf)));
	if (a!=0)
	{
    	_terminal.write((void*)&a,1);
		strcount++;
             
	}
	if (a==0)
	{
	strcount=0;
	}
#endif
	} else 
if ((int)(*((int*)(statusbuf))) & (1<<23))
{
	int a=0;
	_terminal.read(&a,1);
	if ((int)a!=EOF)
	*((char*)mubuf)=(char)a;

}
#if 1
	if ((int)(*((int*)(statusbuf))) & (1<<26))
       {
	DIR *folder;
    struct dirent *entry;
	log("dir 1") ;
	volatile Genode::addr_t recbuf2 =mubuf+0x14;
	volatile Genode::addr_t sendbuf2 =mubuf+0x4;
	char * dirarg;
	char errstring []= {"Invalid path!"};
	Genode::addr_t fromro = (Genode::addr_t)(uint32_t)(*((int*)(recbuf2)));
	if (fromro!=0)
	{  
	 Genode::Attached_io_mem_dataspace _ds_ro(env, fromro,1024*1024*20,true);//, _base(base), _size(size),
	 
	Genode::addr_t xxbuf =  (Genode::addr_t)_ds_ro.local_addr<void>();
	uint32_t rolen = (uint32_t)*((uint32_t*)(char*)xxbuf+16);
	int cmdno = (int)*((int*)(char*)xxbuf);
	if (rolen>0)
	{
		
		dirarg = (char*)malloc(rolen*sizeof(char));
		memset(dirarg,0,rolen);  
		memcpy(dirarg,((char*)xxbuf+32),rolen);
	}
        Libc::with_libc([&] () {
if (cmdno==1) 
{

	if (rolen>0)
		folder= opendir(dirarg);
	else 
		folder = opendir("/");

	int dircount=0;
	memset((char*)xxbuf,0,1024*1024*10); 
  if (folder)
  {
	 while( (entry=readdir(folder)) )
    {

	   memcpy((char*)xxbuf+4+(1024*dircount),(char*)entry->d_name,strlen(entry->d_name));
	    dircount++;

    }
	 *((int*)xxbuf)=dircount;
	 closedir(folder);
	 } else {
	memcpy((char*)xxbuf+4,(char*)errstring,strlen(errstring));
		 dircount=1;
	 *((int*)xxbuf)=dircount;
	 }
}
else {

	memset((char*)xxbuf,0,1024*1024*20); 
FILE * outfile =0;


struct stat loadlen;
int loadfd = open(dirarg,O_RDONLY);
fstat(loadfd,&loadlen);
uint32_t loadsize = loadlen.st_size;
close(loadfd);
Genode::log("loadsize: ",Genode::Hex(loadsize));

close(loadfd);
outfile = fopen(dirarg,"rb");
fread((char*)xxbuf+4,1,loadsize,outfile);
fclose(outfile);
if (loadsize>0)//outfile)
{
  
	 *((uint32_t*)xxbuf)=loadsize;






} else {
	
	memcpy((char*)xxbuf+4,(char*)errstring,strlen(errstring));
	 *((int*)xxbuf)=1;

}
}
});
	}
	while(!((int)(*((int*)(statusbuf))) & (1<<22))) {}
	
	*((int*)sendbuf2)=fromro;
	
       }
#endif
        copycount++;

			  	Libc::with_libc([&] () { nanosleep(&tv, (struct timespec *)NULL);}); 
	if (copycount>40)
	copycount=0;
}

	}
