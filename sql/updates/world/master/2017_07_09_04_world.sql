--
UPDATE `creature_formations` SET `groupAI`=(`groupAI`&~0x004)|0x200 WHERE `groupAI`&0x004;

