#!/bin/sh

#  XTexturePacker.sh
#  X
#
#  Created by leo on 15/1/20.
#

TP="/usr/local/bin/TexturePacker"

if ["${ACTION}" = "clean"]
then
echo "cleaning..."

else
echo "building..."

${TP} --smart-update \
--format cocos2d \
--data ArtResource/Cooked/UI/UI_Battle_Public/UI_Battle_Public-hd.plist \
--sheet ArtResource/Cooked/UI/UI_Battle_Public/UI_Battle_Public-hd.pvr.ccz \
--algorithm MaxRects \
--dither-fs-alpha \
--opt RGBA8888 \
--auto-sd \
--max-width 4096 \
--max-height 4096 \
ArtResource/Raw/UI/UI_Battle_Public/*.png

${TP} --smart-update \
--format cocos2d \
--data ArtResource/Cooked/UI/UI_Battle_xuanbase/UI_Battle_xuanbase-hd.plist \
--sheet ArtResource/Cooked/UI/UI_Battle_xuanbase/UI_Battle_xuanbase-hd.pvr.ccz \
--algorithm MaxRects \
--dither-fs-alpha \
--opt RGBA8888 \
--auto-sd \
--max-width 4096 \
--max-height 4096 \
ArtResource/Raw/UI/UI_Battle_xuanbase/*.png

${TP} --smart-update \
--format cocos2d \
--data ArtResource/Cooked/UI/UI_Battle_hunbase/UI_Battle_hunbase-hd.plist \
--sheet ArtResource/Cooked/UI/UI_Battle_hunbase/UI_Battle_hunbase-hd.pvr.ccz \
--algorithm MaxRects \
--dither-fs-alpha \
--opt RGBA8888 \
--auto-sd \
--max-width 4096 \
--max-height 4096 \
ArtResource/Raw/UI/UI_Battle_hunbase/*.png

${TP} --smart-update \
--format cocos2d \
--data ArtResource/Cooked/UI/UI_Battle_shangbase/UI_Battle_shangbase-hd.plist \
--sheet ArtResource/Cooked/UI/UI_Battle_shangbase/UI_Battle_shangbase-hd.pvr.ccz \
--algorithm MaxRects \
--dither-fs-alpha \
--opt RGBA8888 \
--auto-sd \
--max-width 4096 \
--max-height 4096 \
ArtResource/Raw/UI/UI_Battle_shangbase/*.png

fi
exit 0