UPDATE `creature_template` SET
`minlevel` = '60',
`maxlevel` = '60',
`minhealth` = '6900',
`maxhealth` = '7200',
`minmana` = '9476',
`maxmana` = '9736',
`armor` = '4000',
`speed` = '1.7',
`rank` = '1',
`mindmg` = '600',
`maxdmg` = '1500',
`attackpower` = '1200',
`family` = '16',
`minrangedmg` = '0',
`maxrangedmg` = '0',
`rangedattackpower` = '0',
`resistance1` = '15',
`resistance2` = '15',
`resistance3` = '15',
`resistance4` = '15',
`resistance5` = '15',
`resistance6` = '15',
`ScriptName` = 'npc_kservant' WHERE `entry` = '19685';

DELETE FROM `quest_start_scripts` WHERE `id`='10211';
UPDATE `quest_template` SET `StartScript`='0' WHERE entry=10211;
