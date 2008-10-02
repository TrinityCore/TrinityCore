UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `npcflag`&1024 and `npcflag`&512;
UPDATE `creature_template` SET `npcflag`=`npcflag`& ~1024 WHERE `npcflag`&1024 and (`npcflag`&512)=0;