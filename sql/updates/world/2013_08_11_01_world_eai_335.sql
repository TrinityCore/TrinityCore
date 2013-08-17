UPDATE `creature_ai_scripts` SET `action1_param1`=15 WHERE `id`=1730003; -- Call For Help radius from 0 to 15
UPDATE `creature_ai_scripts` SET `action1_type`=`action2_type`,`action2_type`=0,`action1_param1`=`action2_param1`,`action2_param1`=0 WHERE `id` IN (1772701,3547605); -- Action type gap
UPDATE `creature_ai_scripts` SET `action1_param1`=10255 WHERE `id`=1688002; -- Wrong quest credit (used npc id, should use quest id), fixes quest Testing the Antidote (or at least it should)
