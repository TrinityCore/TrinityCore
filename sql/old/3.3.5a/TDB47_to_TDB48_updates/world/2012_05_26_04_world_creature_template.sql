-- Training dummies
UPDATE `creature_template` SET
    `mechanic_immune_mask` = `mechanic_immune_mask` &~ 0x4000 /* BLEED */
WHERE `ScriptName`='npc_training_dummy';
