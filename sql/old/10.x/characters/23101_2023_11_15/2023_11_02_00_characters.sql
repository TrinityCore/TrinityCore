DELETE ctc, cte FROM `character_trait_config` ctc LEFT JOIN `character_trait_entry` cte ON ctc.`guid` = cte.`guid` AND ctc.`traitConfigId` = cte.`traitConfigId` WHERE ctc.`type` = 3;
