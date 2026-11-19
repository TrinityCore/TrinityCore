ALTER TABLE `conditional_chr_model` MODIFY `ID` int UNSIGNED NOT NULL DEFAULT 0 FIRST;
ALTER TABLE `conditional_chr_model` MODIFY `ChrModelID` int NOT NULL DEFAULT 0 AFTER `ID`;
