#include "StalkerEditorCommands.h"
#include "../StalkerEditorStyle.h"

#define LOCTEXT_NAMESPACE "StalkerEditorModule"
StalkerEditorCommands::StalkerEditorCommands() : TCommands<StalkerEditorCommands>(TEXT("StalkerEditor"), NSLOCTEXT("Contexts", "StalkerEditor", "Stalker Editor"), NAME_None, FStalkerEditorStyle::GetStyleSetName())
{

}

void StalkerEditorCommands::RegisterCommands()
{
	UI_COMMAND(BuildCForm, "BuildCForm", "Build CForm", EUserInterfaceActionType::Button, FInputChord())
	UI_COMMAND(BuildAIMap, "BuildAIMap", "Build AIMap", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(BuildLevelSpawn, "BuildLevelSpawn", "Build LevelSpawn", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(BuildGameSpawn, "BuildGameSpawn", "Build GameSpawn", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ReloadConfigsAndScript, "ReloadConfigsAndScript", "Reload configs and script", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ImportUITextures, "ImportUITextures", "Import UI Textures", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ImportMeshes, "ImportMeshes", "Import Meshes", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ImportPhysicalMaterials, "ImportPhysicalMaterials", "Import Physical Materials", EUserInterfaceActionType::Button, FInputChord());
}

#undef  LOCTEXT_NAMESPACE 