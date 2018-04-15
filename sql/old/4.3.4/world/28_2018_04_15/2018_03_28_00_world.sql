ALTER TABLE `spell_dbc`
CHANGE `SpellInterruptsId` `SpellInterruptsId` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `SpellEquippedItemsId`;

ALTER TABLE `spelleffect_dbc`
ADD COLUMN `Comment` TEXT NOT NULL AFTER `EffectIndex`;

CREATE TEMPORARY TABLE `spelleffectdbc_comments` (
`Id` INT(10) UNSIGNED NOT NULL,
`Comment` TEXT NOT NULL,
PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `spelleffectdbc_comments` (`Id`, `Comment`)
SELECT DISTINCT spe.EffectSpellId, sp.`Comment` FROM `spelleffect_dbc` spe LEFT JOIN spell_dbc sp ON sp.Id = spe.EffectSpellId;

UPDATE `spelleffect_dbc` spe, `spelleffectdbc_comments` spc SET spe.`Comment`=spc.`Comment` WHERE spe.`EffectSpellId` = spc.`Id`;
DROP TABLE `spelleffectdbc_comments`;
