#!/bin/bash

# Set client and server directories as environment variables
# if you don't want to enter them here
if [ -z $CLIENT_DIR ]; then
echo -n "Enter directory where client files are located: "
read CLIENT_DIR

if ! cd $CLIENT_DIR; then
        echo "Cannot access $CLIENT_DIR"
        exit 1
fi
if [ ! -d $CLIENT_DIR/Data ]; then
        echo "Cannot find client files in $CLIENT_DIR"
        exit 1
fi
fi

if [ -z $SERVER_DIR ]; then
echo -n "Enter directory where server files are located: "
read SERVER_DIR

if ! cd $SERVER_DIR; then
        echo "Cannot access $SERVER_DIR"
        exit 1
fi
fi

# These should all be correct on a standard installation
DATA_DIR=${SERVER_DIR}/data
MAPEXTRACTOR=${SERVER_DIR}/bin/mapextractor
VMAP4EXTRACTOR=${SERVER_DIR}/bin/vmap4extractor
VMAP4ASSEMBLER=${SERVER_DIR}/bin/vmap4assembler
MMAPS_GENERATOR=${SERVER_DIR}/bin/mmaps_generator

check_files() {
for i in $MAPEXTRACTOR $VMAP4EXTRACTOR $VMAP4ASSEMBLER $MMAPS_GENERATOR
do
	if [[ ! -x $i ]]
	then
		echo "Invalid executable: $i"
		echo "Check that the extraction tools are installed correctly."
		exit
	fi
done
}

show_header() {
echo "======================================================"
echo "Trinitycore (master) DBC, Maps, VMaps & MMaps Extractor"
echo "======================================================"
echo
echo
echo "Client directory: ${CLIENT_DIR}"
echo "Data directory:   ${DATA_DIR}"
echo
}

extract_dbc_maps() {
echo
echo "Extracting DBC, gt, Camera and Maps files"
echo
echo "-- Using $MAPEXTRACTOR"
echo "-- Copying extracted data to ${DATA_DIR}"
if [[ ! -d ${DATA_DIR} ]]
then
	echo "-- Creating ${DATA_DIR}"
	mkdir ${DATA_DIR}
fi
echo "-- Starting in 5 seconds"
sleep 5

cd ${CLIENT_DIR}
$MAPEXTRACTOR

echo "-- Extraction complete, copying dbc, gt and maps files"
cp -r dbc gt maps ${DATA_DIR}
if [[ -d ${CLIENT_DIR}/cameras ]]
then
	echo "-- Camera files found, copying"
	cp -r cameras ${DATA_DIR}
fi

echo "-- Done"
echo
}

extract_vmaps() {
echo
echo "Extracting Visual Maps"
echo
echo "-- Using ${VMAP4EXTRACTOR}"
echo "-- Using ${VMAP4ASSEMBLER}"
echo "-- Copying extracted data to ${DATA_DIR}/vmaps"
echo "-- Starting in 5 seconds"
sleep 5

cd ${CLIENT_DIR}
$VMAP4EXTRACTOR
mkdir vmaps
$VMAP4ASSEMBLER Buildings vmaps

echo "-- Extraction complete, copying files"
cp -r vmaps ${DATA_DIR}
echo "-- Done"
echo
}

extract_mmaps() {
echo
echo "Extracting Movement Maps (this may take a while)"
echo
echo "-- Using ${MMAPS_GENERATOR}"
echo "-- Copying extracted data to ${DATA_DIR}/mmaps"
echo "-- Starting in 5 seconds"
sleep 5

cd ${CLIENT_DIR}
mkdir mmaps
$MMAPS_GENERATOR
echo "-- Extraction complete, copying files"
cp -r mmaps ${DATA_DIR}
echo "-- Done"
echo
}

clean_client() {
echo
echo "Cleaning up extracted client files (copied server files are not removed)"
echo
echo "Deleting the following directories from ${CLIENT_DIR}"
echo "-- Buildings, cameras, dbc, gt, maps, mmaps, vmaps"
echo
echo "Enter y to continue or anything else to cancel"
read a
if [[ ${a} = "y" ]]
then
	cd ${CLIENT_DIR}
	rm -fr Buildings cameras dbc gt maps mmaps vmaps
	echo "Done"
fi
}

show_menu() {
PS3='Enter choice: '
options=("Extract DBC and Maps files" "Extract Visual Maps (VMaps)" "Extract Movement Maps (MMaps)"
"Extract all files" "Clean up client" "Quit")
select opt in "${options[@]}"
do
	case $opt in
		"Extract DBC and Maps files")
			extract_dbc_maps	
			show_header
			;;
		"Extract Visual Maps (VMaps)")
			extract_vmaps
			show_header
			;;
		"Extract Movement Maps (MMaps)")
			extract_mmaps
			show_header
			;;
		"Extract all files")
			extract_dbc_maps
			extract_vmaps
			extract_mmaps
			echo "All files extracted"
			break	
			;;
		"Clean up client")
			clean_client
			;;
		"Quit")
			echo
			break
			;;
		*) echo "$REPLY is not a valid option";;
	esac
done
}

show_header
check_files
show_menu
