-- Shatterspear Laborers
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~(0x100|0x200|0x8000|0x20000000), `unit_flags2`=`unit_flags2`&~0x1, `unit_flags3`=`unit_flags3`&~0x2000 WHERE `entry`=32861;
UPDATE `creature` SET `unit_flags`=(0x100|0x200|0x8000|0x20000000), `unit_flags2`=0x1, `unit_flags3`=0x2000 WHERE `guid` IN(260181, 260182, 260188, 260189, 260190);

-- Shatterspear Raiders
UPDATE `creature` SET `unit_flags`=(0x100|0x200|0x8000|0x20000000), `unit_flags2`=0x1, `unit_flags3`=0x2000 WHERE `guid` IN(315289, 315293, 315292, 315305);
