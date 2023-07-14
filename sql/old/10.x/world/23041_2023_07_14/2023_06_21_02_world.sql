-- Change spawntimesecs from 7200 to 120. 7200 is for instances not starter zones.
UPDATE `creature` SET `spawntimesecs`=120 WHERE `id` IN (150228,150229,161224,161228,161130,161131,161133,164826,164827);
