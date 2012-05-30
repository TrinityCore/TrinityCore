-- Remove unused flag
UPDATE `characters` SET `extra_flags`=`extra_flags`&~0x40;
