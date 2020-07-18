-- 
DELETE FROM `creature` WHERE `guid`=118724 AND `id`=27122;
UPDATE `creature` SET `equipment_id`=1 WHERE `guid`=52290;
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=26942;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=45491, `target_type`=19, `target_param1`=27180, `target_param2`=10, `comment`="Decrepit Necromancer - Out of Combat - Cast Necrotic Purple Beam" WHERE `entryorguid`=26942 AND `source_type`=0 AND `id`=0;
