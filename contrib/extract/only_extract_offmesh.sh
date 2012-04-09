#!/bin/sh

# Copyright (C) 2005-2012 MaNGOS project <http://getmangos.com/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

## Syntax of this helper
## First param must be number of to be used CPUs (only 1, 2, 3, 4 supported) or "offmesh" to recreate the special tiles from the OFFMESH_FILE
## Second param can be an additional filename for storing log
## Third param can be an addition filename for storing detailed log

## Additional Parameters to be forwarded to MoveMapGen, see mmaps/readme for instructions
PARAMS="--silent"

## Already a few map extracted, and don't care anymore
EXCLUDE_MAPS=""
#EXCLUDE_MAPS="0 1 530 571" # example to exclude the continents

## Offmesh file
OFFMESH_FILE="offmesh.txt"

## Normal log file (if not overwritten by second param
LOG_FILE="MoveMapGen.log"
## Detailed log file
DETAIL_LOG_FILE="MoveMapGen_detailed.log"

## ! Use below only for finetuning or if you know what you are doing !

## All maps
MAP_LIST_A="1 37 543 595 289 572 529 562 531 269 47 649 650 599 548 559 429 230 573 349 13 25 409 229 43 48 546 553 547 604 545 90 576"
MAP_LIST_B="571 628 560 509 723 532 607 600 668 33 585 566 389 601 369 129 550 189 542 70 109 554 632 552 555 540 598 450 558 249 35 624 557"
MAP_LIST_C="0 631 609 534 533 619 469 602 329 580 615 578 36 556 44 565 544 34 617 608 618 449 616 42 451 582 584 586 587 588 589 590 591 592"
MAP_LIST_D="530 169 575 603 309 574 30 564 568 209 724 658 489  593 594 596 597 605 606 610 612 613 614 620 621 622 623 641 642 647 672 673 712 713 718"
MAP_LIST_D1="209 724 658 489 606 610 612 613 614 620 621"
MAP_LIST_D2="169 575 603 309 574 30 564 568 622 623 641 642 647 672 673 712 713 718"
MAP_LIST_D3="530 593 594 596 597 605"

badParam()
{
  echo "ERROR! Bad arguments!"
  echo "You can (re)extract mmaps with this helper script,"
  echo "or recreate only the tiles from the offmash file"
  echo
  echo "Call with number of processes (1 - 4) to create mmaps"
  echo "Call with 'offmesh' to reextract the tiles from offmash file"
  echo
  echo "For further fine-tuning edit this helper script"
  echo
}

if [ "$#" = "3" ]
then
  LOG_FILE=$2
  DETAIL_LOG_FILE=$3
elif [ "$#" = "2" ]
then
  LOG_FILE=$2
fi

# Offmesh file provided?
OFFMESH=""
if [ "$OFFMESH_FILE" != "" ]
then
  if [ ! -f "$OFFMESH_FILE" ]
  then
    echo "ERROR! Offmesh file $OFFMESH_FILE could not be found."
    echo "Provide valid file or none. You need to edit the script"
    exit 1
  else
    OFFMESH="--offMeshInput $OFFMESH_FILE"
  fi
fi

# Function to process a list
createMMaps()
{
  for i in $@
  do
    for j in $EXCLUDE_MAPS
    do
      if [ "$i" = "$j" ]
      then
        continue 2
      fi
    done
    ./MoveMapGen $PARAMS $OFFMESH $i | tee -a $DETAIL_LOG_FILE
    echo "`date`: (Re)created map $i" | tee -a $LOG_FILE
  done
}

createHeader()
{
  echo "`date`: Start creating MoveMaps" | tee -a $LOG_FILE
  echo "Used params: $PARAMS $OFFMESH" | tee -a $LOG_FILE
  echo "Detailed log can be found in $DETAIL_LOG_FILE" | tee -a $LOG_FILE
  echo "Start creating MoveMaps" | tee -a $DETAIL_LOG_FILE
  echo
  echo "Be PATIENT - This will take a long time and might also have gaps between visible changes on the console."
  echo "WAIT until you are informed that 'creating MoveMaps' is 'finished'!"
}

# Create mmaps directory if not exist
if [ ! -d mmaps ]
then
  mkdir mmaps
fi

# Param control
case "$1" in
  "1" )
    createHeader $1
    createMMaps $MAP_LIST_A $MAP_LIST_B $MAP_LIST_C $MAP_LIST_D &
    ;;
  "2" )
    createHeader $1
    createMMaps $MAP_LIST_A $MAP_LIST_D &
    createMMaps $MAP_LIST_B $MAP_LIST_C &
    ;;
  "3" )
    createHeader $1
    createMMaps $MAP_LIST_A $MAP_LIST_D1&
    createMMaps $MAP_LIST_B $MAP_LIST_D2&
    createMMaps $MAP_LIST_C $MAP_LIST_D3&
    ;;
  "4" )
    createHeader $1
    createMMaps $MAP_LIST_A &
    createMMaps $MAP_LIST_B &
    createMMaps $MAP_LIST_C &
    createMMaps $MAP_LIST_D &
    ;;
  "offmesh" )
    echo "`date`: Recreate offmeshs from file $OFFMESH_FILE" | tee -a $LOG_FILE
    echo "Recreate offmeshs from file $OFFMESH_FILE" | tee -a $DETAIL_LOG_FILE
    while read map tile line
    do
      ./movement_extractor $PARAMS $OFFMESH $map --tile $tile | tee -a $DETAIL_LOG_FILE
      echo "`date`: Recreated $map $tile from $OFFMESH_FILE" | tee -a $LOG_FILE
    done < $OFFMESH_FILE &
    ;;
  * )
    badParam
    exit 1
    ;;
esac

wait

echo  | tee -a $LOG_FILE
echo  | tee -a $DETAIL_LOG_FILE
echo "`date`: Finished creating MoveMaps" | tee -a $LOG_FILE
echo "`date`: Finished creating MoveMaps" >> $DETAIL_LOG_FILE
