-- 
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`IN (1735,37589,10676,14369,17827,22258,23101,25078,25093,28209,28210,24956,26547,33642,29778,29143,29145,29728,20165);
UPDATE `creature_template` SET `npcflag`=65537,`type_flags`=134217728 WHERE `entry`=3628;
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry` IN (5835,21859,5627,17764,25924);
