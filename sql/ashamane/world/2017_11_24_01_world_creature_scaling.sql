UPDATE 
  creature_template_scaling 
  LEFT JOIN creature_template 
    ON creature_template.entry = creature_template_scaling.`Entry` SET creature_template.minlevel = creature_template_scaling.`LevelScalingMin`,
  creature_template.maxlevel = creature_template_scaling.`LevelScalingMax` ;
  
ALTER TABLE `creature_template_scaling` DROP COLUMN `LevelScalingMin`, DROP COLUMN `LevelScalingMax`;
