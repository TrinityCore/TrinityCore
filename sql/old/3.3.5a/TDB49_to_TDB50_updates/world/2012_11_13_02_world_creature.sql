-- Fix [Q]{A/H} Meet At The Grave
UPDATE `creature_template_addon` SET `auras`='10848' WHERE `entry`=9299; -- allow to be seen in world of death
UPDATE `creature_template` SET `npcflag`=32770,`unit_flags`=768 WHERE `entry`=9299; -- makes unseen in world of living
