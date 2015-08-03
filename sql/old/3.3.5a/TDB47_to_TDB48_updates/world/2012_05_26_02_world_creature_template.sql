-- Training dummies
UPDATE `creature_template` SET
    `flags_extra`=0x40000, /* NO_SKILLGAIN */
    `mechanic_immune_mask`=0x20|0x4000 /* GRIP|BLEED */ /* two of the templates already had bleed immunity, is that correct? */
WHERE `ScriptName`='npc_training_dummy';
