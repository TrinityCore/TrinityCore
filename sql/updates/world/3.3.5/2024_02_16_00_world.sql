-- Quest "Abandoned Mail" should have "Autocomplete" flag
UPDATE `quest_template` SET `Flags`=`Flags`| 65536 WHERE `ID`=12711;
