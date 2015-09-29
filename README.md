PlayDisplay
========

Embedded device that listens for music and displays relevant artwork and information.


**End-to-end**  

* SoundMonitor picks up Audio from hardwareController  
* SoundMonitor sends Audio through SampleShipper  
* SampleShipper returns Song object  
* PlayDisplay picks up Song object and delivers to Display  

Top level
--------

PlayDisplay  
* Grabs Song objects from SoundMonitor, delivers to Displayer

**Back-End functions**

SoundMonitor (SM)
* controls hardware / shipping module
* returns Song objects
* Audio is not passed any higher than this level.  
* Update loops are done at this level  
* Can be asked for "status" string (monitoring, IDing, ready)

HardwareController
* Asked by SM to record, returns Audio object 

SampleShipper  
* takes Audio, sends through EchoPrint, returns Song to SoundMonitor

EchoPrint
* uses Codegen library
* PCM: buffer of floats, mono, 11025Hz
* Returns 

**Front-End functions**

Displayer - Takes Song object, displays information