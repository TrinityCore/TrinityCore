ALTER TABLE `character_aura_effect` 
  MODIFY `amount` double NOT NULL DEFAULT 0 AFTER `effectIndex`,
  MODIFY `baseAmount` double NOT NULL DEFAULT 0 AFTER `amount`;

ALTER TABLE `pet_aura_effect` 
  MODIFY `amount` double NOT NULL DEFAULT 0 AFTER `effectIndex`,
  MODIFY `baseAmount` double NOT NULL DEFAULT 0 AFTER `amount`;
