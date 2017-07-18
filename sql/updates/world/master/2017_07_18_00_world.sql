UPDATE `spell_custom_attr` SET `attributes`=`attributes` & ~(2|4);
DELETE FROM `spell_custom_attr` WHERE `attributes`=0;
