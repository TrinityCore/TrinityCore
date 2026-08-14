-- Cast Summon Khadgar's Servant even on mounted player
UPDATE `smart_scripts` SET `action_param2`=2 WHERE `entryorguid`=1816600 AND `source_type`=9 AND `id`=1;
