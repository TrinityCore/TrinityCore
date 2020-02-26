-- Infernal (89)
UPDATE `creature_template` SET `spell_school_immune_mask`=`spell_school_immune_mask`|4 WHERE `entry`=89;

-- Water Elemental (501)
UPDATE `creature_template` SET `spell_school_immune_mask`=`spell_school_immune_mask`|16 WHERE `entry`=501;

-- Greater Earth Elemental (15352)
UPDATE `creature_template` SET `spell_school_immune_mask`=`spell_school_immune_mask`|8 WHERE `entry`=15352;

-- Greater Fire Elemental (15438)
UPDATE `creature_template` SET `spell_school_immune_mask`=`spell_school_immune_mask`|4 WHERE `entry`=15438;
