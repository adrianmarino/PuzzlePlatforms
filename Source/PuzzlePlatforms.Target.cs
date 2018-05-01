using UnrealBuildTool;
using System.Collections.Generic;

public class PuzzlePlatformsTarget : TargetRules
{
	public PuzzlePlatformsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("PuzzlePlatforms");
	}
}
