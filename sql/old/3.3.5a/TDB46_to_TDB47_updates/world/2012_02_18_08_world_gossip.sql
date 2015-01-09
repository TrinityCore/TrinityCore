-- Fix mistake in Fallen Hero of the Horde gossip update
UPDATE `conditions` SET `ConditionValue1`=2784,`Comment`='Show gossip text if player has quest 2801 or 2784 completed' WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=840 AND `ConditionValue1`=2704;
UPDATE `conditions` SET `Comment`='Show gossip text if player has quest 2801 or 2784 completed' WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=840 AND `ConditionValue1`=2801;
UPDATE `conditions` SET `ConditionValue1`=2784,`Comment`='Show gossip option if player has quest 2784 but not complete' WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=840 AND `ConditionValue1`=2704;
UPDATE `smart_scripts` SET `action_param1`=2784 WHERE `entryorguid`=7572 AND `id`=0;
