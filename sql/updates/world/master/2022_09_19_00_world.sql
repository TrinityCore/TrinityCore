-- 
ALTER TABLE `serverside_spell_effect` 
    MODIFY COLUMN `DifficultyID` int NOT NULL DEFAULT 0 AFTER `SpellID`,
    MODIFY COLUMN `EffectAura` smallint NOT NULL DEFAULT 0 AFTER `EffectAttributes`,
    MODIFY COLUMN `EffectBasePoints` int NOT NULL DEFAULT 0 AFTER `EffectAuraPeriod`,
    ADD COLUMN `EffectDieSides` int NOT NULL AFTER `EffectChainTargets`;
