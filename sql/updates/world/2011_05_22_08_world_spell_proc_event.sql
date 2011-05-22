-- Eradication should not have internal cooldown
UPDATE `spell_proc_event` SET `Cooldown`=0 WHERE `entry` IN (47195,47196,47197); 
