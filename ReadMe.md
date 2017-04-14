First you need to make sure that you have the raw files

#Compiling
You can compile the code with $ make

#Running
To run the program, use:

./volImage <row files path>/<row files prefix> [-d i j output_file_name] [-x i output_file_name] [-g i output_file_name]

Be aware that if your row files are in a folder, you need to specify that ie. folder_path/MRI

The last option is for the extra credit

#cleaning
$ make clean - this should remove all the object files

#Others
If you get an error saying that incl.defs is not defined, run:
make depend

All the output files (.row and .data) will be in the root directry where the driver file is.

Thats it :)