SET @BUILD := 51536;

DELETE FROM `chr_customization_choice_locale` WHERE (`VerifiedBuild`>0 AND `VerifiedBuild`<@BUILD);
