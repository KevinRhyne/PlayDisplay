PlayDisplay
========

Embedded device that listens for music and displays relevant artwork and information.


**End-to-end**  
SoundMonitor picks up Audio from hardwareController  
SoundMonitor sends Audio through SampleShipper  
SampleShipper returns Song object  
PlayDisplay picks up Song object and delivers to Display  

Top level
--------

PlayDisplay  
* Grabs Song objects from SoundMonitor, delivers to Displayer

**Back-End functions**

SoundMonitor  
* controls hardware / shipping module and returns song information.  
* Audio is not passed any higher than this level.  
* Update loops are done at this level  

HardwareController - Asked to record, returns Audio object  

**Front-End functions**

Displayer