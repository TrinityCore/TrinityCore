#!/bin/bash

##
# Copyright Eilo, Hispano, thnx to Jeutie
# Copyright 2012 Badanni <version for GNU/Linux>


#setlocal EnableDelayedExpansion
WorldTraducciones="All_World_Traducciones.sql"
WorldRean="All_World_Rean.sql"
WorldUpdates="All_World_Updates.sql"
CharactersRean="All_Characters_Rean.sql"
CharactersUpdates="All_Characters_Updates.sql"
AuthRean="All_Auth_Rean.sql"
AuthUpdates="All_Auth_Updates.sql"
Auxiliar="aux.sql"

function borrar_antiguos () {
	if [ -f $AuthUpdates ]; then
	 rm $AuthUpdates
	fi
	if [ -f $AuthRean ]; then
	 rm $AuthRean
	fi
	if [ -f $CharactersUpdates ]; then
	 rm $CharactersUpdates
	fi
	if [ -f $CharactersRean ]; then
	 rm $CharactersRean
	fi
	if [ -f $WorldUpdates ]; then
	 rm $WorldUpdates
	fi
	if [ -f $WorldTraducciones ]; then
	 rm $WorldTraducciones
	fi
	if [ -f $WorldRean ]; then
	 rm $WorldRean
	fi
	}
function borrar_auxiliar () {
	if [ -f $1 ]; then
		rm $1
	fi
	}
function generar_archivo () {
	for a in $2 
		do
			borrar_auxiliar $Auxiliar
			echo "/*" >> $1
			echo "* $a" >> $1
			echo "*/" >> $1
			cat $1 $a > $Auxiliar
			cp $Auxiliar $1
			echo "" >> $1
			echo "" >> $1
			echo "$a"
		done
	}
function mensaje () {
	if [ $1 == 1 ]; then
		echo "##########################################################"
		echo "##                                                      ##"
		echo "##     ReanEmu - Archivo de unificacion de SQL's        ##"
		echo "##                                                      ##"
		echo "##########################################################"
		echo "By Eilo and Hispano, thnx to Jeutie"
		echo "version for GNU/Linux by badanni"
		echo .
		echo .
		echo .
		echo "Las siguientes lineas unirán todos los archivos sql que"
		echo "esten dentro de la carpeta sql/update de manera que ahora"
		echo "puedan importar todas las actualizaciones de la carpeta"
		echo "con tan solo un archivo en vez de una por una."
		echo .
		echo .
		echo .
		echo "presiones Ctrl+C para cancelar caso contrario en 5 segundos"
		echo "continuara"
		sleep 5
		echo "El proceso empezara AHORA!"
	else
		echo "ReanEmu"
		sleep 5
	fi
	}

mensaje 1
borrar_antiguos
generar_archivo $WorldRean "updates/world/reanemu/*.sql"
generar_archivo $WorldTraducciones "updates/world/traducciones/*.sql"
generar_archivo $WorldUpdates "updates/world/*.sql"
generar_archivo $CharactersUpdates "updates/characters/*.sql"
generar_archivo $CharactersRean "updates/characters/reanemu/*.sql"
generar_archivo $AuthUpdates "updates/auth/*.sql"
generar_archivo $AuthRean "updates/auth/reanemu/*.sql"
borrar_auxiliar $Auxiliar
mensaje 2
