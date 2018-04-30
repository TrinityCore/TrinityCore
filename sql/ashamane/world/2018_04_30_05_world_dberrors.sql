UPDATE `disenchant_loot_template` SET `Item`='16204' WHERE  `Item`=10978;
UPDATE `disenchant_loot_template` SET `Item`='16202' WHERE  `Item`=11084;
UPDATE `disenchant_loot_template` SET `Item`='16204' WHERE  `Item`=11083;
UPDATE `disenchant_loot_template` SET `Item`='14343' WHERE  `Item`=11082;
UPDATE `disenchant_loot_template` SET `Item`='16202' WHERE  `Item`=11138;
UPDATE `disenchant_loot_template` SET `Item`='16204' WHERE  `Item`=11135;
UPDATE `disenchant_loot_template` SET `Item`='14343' WHERE  `Item`=11137;
UPDATE `disenchant_loot_template` SET `Item`='16202' WHERE  `Item`=11139;
UPDATE `disenchant_loot_template` SET `Item`='16202' WHERE  `Item`=11174;
UPDATE `disenchant_loot_template` SET `Item`='16204' WHERE  `Item`=11177;
UPDATE `disenchant_loot_template` SET `Item`='16202' WHERE  `Item`=11175;
UPDATE `disenchant_loot_template` SET `Item`='16204' WHERE  `Item`=11176;
UPDATE `disenchant_loot_template` SET `Item`='14343' WHERE  `Item`=11178;
UPDATE `disenchant_loot_template` SET `Item`='16202' WHERE  `Item`=20725;
UPDATE `disenchant_loot_template` SET `Item`='16202' WHERE  `Entry`=7 AND `Item`=10998;
UPDATE `disenchant_loot_template` SET `Item`='10202' WHERE  `Entry`=8 AND `Item`=10998;
UPDATE `disenchant_loot_template` SET `Item`='14343' WHERE  `Entry`=17 AND `Item`=11134;
UPDATE `disenchant_loot_template` SET `Item`='14343' WHERE  `Entry`=18 AND `Item`=11134;

REPLACE INTO `disenchant_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(107, 52721, 0, 100, 0, 1, 1, 1, 1, NULL),
(108, 52722, 0, 100, 0, 1, 1, 1, 1, NULL);

UPDATE `disenchant_loot_template` SET `Chance`='50' WHERE  `Entry`=136;

DELETE FROM `creature_addon` WHERE  `guid` IN (20343418,20454434);
DELETE FROM `gameobject_addon` WHERE  `guid` IN (20361660,20355291,20361666,20361655,20361653,19803152,20346831,20355289,20345914,20345937,20345895,20345896,20361658,20362350,20355292,20356427,20345922,20357619,20345939,20345940,20345941,20345942,20355287,20361692,20361657,20346277,20346570,20346832,20356544,20346833,20346614,20357623,20361641,20346572,20361640,20361650,20346601,20361651,20346834,20347174,20347175,20347502,20347435,20347585,20350114,20352433,20350603,20350602,20356126,20356566,20356568,20356565,20350606,20356423,20356411,20350610,20350611,20350612,20350614,20350624,20356070,20356139,20356561,20355283,20355284,20355288,20355296,20355294,20355295,20357630,20357628,20357620,20361676,20361683,20361677,20361656,20361675,20361681,20361684,20355290,20361696,20361697,20361682,20361689,20361674,20355293,20361685,20361698,20361699,20361710,20361711,20361712,20362339,20362347,20362348,20374093,20374097);


El archivo adjunto contiene 174 reparaciones del DBErrors Log, correspondientes a:

* 75 reparaciones de 'disenchant_loot_template'.
* 2 reparaciones de `creature_addon`.
* 97 reparaciones de `gameobject_addon`.

Tipos de líneas involucradas:

-Table 'disenchant_loot_template' Entry 5 Item 10978: item entry not listed in `item_template` - skipped: reemplazadas referencias de items que ya no existen.

-Table 'disenchant_loot_template' Entry 9 does not exist: solucionado automáticamente con la trparación anterior.

-Table 'disenchant_loot_template' entry 136 group 1 has total chance > 100% (200.000000): recalibrado porcentaje.

-Creature (GUID: 20343418) does not exist but has a record in `creature_addon`: eliminadas referencias de creatures borradas en anterior update.

-GameObject (GUID: 20361660) does not exist but has a record in `gameobject_addon`: eliminadas referencias de objects borrados en anterior update.
