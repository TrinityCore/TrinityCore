-- "The Sprouted Fronds" quest is missing flag "Autocomplete"
UPDATE `quest_template` SET `Flags`=`Flags`| 65536 WHERE `ID`=2399;
