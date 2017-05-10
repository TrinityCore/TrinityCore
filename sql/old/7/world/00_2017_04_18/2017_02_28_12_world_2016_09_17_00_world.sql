-- "Remnant of Dahlia Suntouch" should be NPC immune
UPDATE `creature_template` SET `unit_flags`=(`unit_flags`|0x200) WHERE `entry`=27683;
