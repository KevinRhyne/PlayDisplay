PlayDisplay
========

Standalone embedded device listens to music in a room and displays album artwork and release info.


**End-to-end: Overview**  

PlayDisplay takes a microphone recording, generates a fingerprint code, and requests an matching fingerprint from a user-run EchoPrint server (containing the music fingerprint database). Once PlayDisplay recieves the track information, artwork is retrieved from an online album artwork database and draws the screen with the artwork, track, artist, and album information.

**End-to-end: Detailed**

1. **SoundMonitor** object requests a new microphone sample through **AudioInputController** object.
2. **SoundMonitor** passes sample filepath through to **SampleShipper** and then through to **EchoPrint** object.
3. **EchoPrint** object generates a fingerprint code for the *sample fingerprint*.
4. The *sample fingerprint* is sent to the EchoPrint server to compare against a database of *source fingerprints*.
5. The EchoPrint server responds with a JSON formatted string with track, album, and artist information.
6. **SampleShipper** recieves the JSON string and constructs a **Song** object by decoding the JSON string.
7. **SampleShippe**r searches the [MusicBrainz](https://musicbrainz.org/doc/Development/JSON_Web_Service) database to retrieve the album's MBID required for artwork retrieval.
8. **SampleShipper** uses the [libcoverart](https://musicbrainz.org/doc/libcoverart) library to fetch artwork from the [Cover Art Archive](https://coverartarchive.org/).
9. The **Song** object is then returned back through the object hierarchy and passed to the **Displayer** object.
10. **Displayer** object draws the screen with artwork and information.

Repeat forever.

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
