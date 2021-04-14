UPDATE `creature_template` SET `faction`=35 WHERE `entry` IN (27881,28094,28366);
DELETE FROM `conditions` WHERE `SourceEntry`=52226 AND `SourceTypeOrReferenceId`=17;
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `action_type`=36;
