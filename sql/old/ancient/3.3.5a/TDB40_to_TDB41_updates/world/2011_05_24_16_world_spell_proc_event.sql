-- Fixed Omen of Clarity proc
UPDATE `spell_proc_event` SET `ppmRate`=0,`CustomChance`=6,`Cooldown`=10 WHERE `entry`=16864;
