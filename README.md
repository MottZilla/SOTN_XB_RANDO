# SOTN_XB_RANDO
Randomizer for XBLA version of SotN.

Getting Started:
1. Obtain SotN Usa XBLA package file. Should be named: 9F2DAA064D494AA82B43B65362C59E9B89A88F8F58
It should have a CRC32 value of: CBC68CD8

2. Use the program wxPirs or Velocity ( https://github.com/Gualdimar/Velocity/ ) to extract the files from the SotN XBLA package file to a folder.

3. Use the program XexTool to decrypt the default.xex file. Commands are:
* 3a. xextool -c u default.xex
* 3b. xextool -e u default.xex

Once you have your folder with the extracted files and decrypted the default.xex file you do not need to do steps 1 through 3 again.

4. Run SotN_XB_RANDO. Select the decrypted default.xex file and then check the options you want. Click Randomize. 

5. After randomizing successfully you must load the Rando.xex file in Xenia. If using modded original hardware replace your default.xex with Rando.xex

This is beta software. Bugs may exist.
