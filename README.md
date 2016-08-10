PlayDisplay
========

Standalone embedded device listens to music in a room and displays album artwork and release info.

End-to-end
--------
**Overview**  

PlayDisplay takes a microphone recording, generates a fingerprint code, and requests a matching fingerprint from a user-run EchoPrint server (containing the music fingerprint database). Once PlayDisplay recieves the track information, artwork is retrieved from an online album artwork database and draws the screen with the artwork, track, artist, and album information.

**Detailed**

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

Class Hierarchy
--------
![UML classes for PlayDisplay](https://github.com/KevinRhyne/PlayDisplay/blob/master/UML_PNG.png)
