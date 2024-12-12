# SOTN_XB_RANDO
Randomizer for XBLA version of SotN.

Getting Started:
1. Obtain SotN Usa XBLA package file. Should be named: 9F2DAA064D494AA82B43B65362C59E9B89A88F8F58
It should have a CRC32 value of: CBC68CD8
You can use this guide to backup the file from your Xbox 360: https://github.com/xenia-project/xenia/wiki/Quickstart

2. Use LIVE_Extract on this repository to extract the files from the SotN XBLA package file to a folder. Download LIVE_Extract: https://github.com/MottZilla/SOTN_XB_RANDO/blob/main/LIVE_Extract_Release_20241211.zip
 Be sure to have LIVE_Extract, decrypt.xor, and your SotN file in the same folder! Alternative programs are wxPirs or Velocity ( https://github.com/Gualdimar/Velocity/ )

2b. If you did not use LIVE_Extract or it could not decrypt the XEX then you must use the program XexTool to decrypt the default.xex file. Use this command:
xextool -e u default.xex

Once you have your folder with the extracted files and decrypted the default.xex file you do not need to do steps 1 through 2b again. You may want to backup the extracted files.

Download the latest release and the Auto Tracker from Releases: https://github.com/MottZilla/SOTN_XB_RANDO/releases

3. Run SotN_XB_RANDO. Select the decrypted default.xex file and then check the options you want. Click Randomize. 

4. After randomizing successfully you must load the Rando.xex file in Xenia. If using modded original hardware replace your default.xex with Rando.xex or use file manager to load Rando.xex

This is beta software. Bugs may exist.
