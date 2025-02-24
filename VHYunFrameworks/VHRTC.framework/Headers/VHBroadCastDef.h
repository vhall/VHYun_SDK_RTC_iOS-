//
//  VHBroadCastDef.h
//  VhallRTC
//
//  Created by vhall on 2020/6/1.
//  Copyright © 2020 ilong. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef VHBroadCastDef_h
#define VHBroadCastDef_h

//http://wiki.vhallops.com/display/media/Room#Room-%E9%85%8D%E7%BD%AE%E6%97%81%E8%B7%AF%E5%8F%82%E6%95%B0
// 旁路视频Profile
#define PROFILES    @[\
    @{@"resolution":@[@640,@480],@"framerate":@25,@"bitrate":@700},\
    @{@"resolution":@[@848,@480],@"framerate":@25,@"bitrate":@750},\
    @{@"resolution":@[@720,@540],@"framerate":@25,@"bitrate":@950},\
    @{@"resolution":@[@960,@540],@"framerate":@25,@"bitrate":@1150},\
    @{@"resolution":@[@960,@720],@"framerate":@25,@"bitrate":@1400},\
    @{@"resolution":@[@1280,@720],@"framerate":@25,@"bitrate":@1600},\
    @{@"resolution":@[@1280,@960],@"framerate":@25,@"bitrate":@1600},\
    @{@"resolution":@[@1712,@960],@"framerate":@25,@"bitrate":@1900},\
    @{@"resolution":@[@1440,@1080],@"framerate":@25,@"bitrate":@1800},\
    @{@"resolution":@[@1920,@1080],@"framerate":@25,@"bitrate":@2200},\
\
    @{@"resolution":@[@480,@848],@"framerate":@25,@"bitrate":@750},\
    @{@"resolution":@[@540,@960],@"framerate":@25,@"bitrate":@1150},\
    @{@"resolution":@[@720,@1280],@"framerate":@25,@"bitrate":@1600},\
    @{@"resolution":@[@1080,@1920],@"framerate":@25,@"bitrate":@2200}]

/// 注释代表当前枚举选项的 宽高比 分辨率（宽x高）帧率 码率 (kbps)
typedef NS_ENUM(NSInteger,  BroadcastDefinition) {
    BROADCAST_VIDEO_PROFILE_480P_0   = 0,//    4:3    640x480    25    700
    BROADCAST_VIDEO_PROFILE_480P_1   = 1,//    16:9    852x480    25    750
    BROADCAST_VIDEO_PROFILE_540P_0   = 2,//
    BROADCAST_VIDEO_PROFILE_540P_1   = 3,//
    BROADCAST_VIDEO_PROFILE_720P_0   = 4,//    4:3    960x720    25    1400
    BROADCAST_VIDEO_PROFILE_720P_1   = 5,//    16:9    1280X720    25    1600
    BROADCAST_VIDEO_PROFILE_960P_0   = 6,//    4:3    1280x960    25    1600
    BROADCAST_VIDEO_PROFILE_960P_1   = 7,//
    BROADCAST_VIDEO_PROFILE_1080P_0  = 8,//    4:3    1440X1080    25    1800
    BROADCAST_VIDEO_PROFILE_1080P_1  = 9,//    16:9    1920X1080    25    2200
    
    /*以下新增竖版旁路，（注意当使用竖版分辨率时，仅支持部分布局模板，含：
     CANVAS_LAYOUT_PATTERN_FLOAT_2_1DR 8
     CANVAS_LAYOUT_PATTERN_FLOAT_2_1DL 9
     CANVAS_LAYOUT_EX_PATTERN_FLOAT_2_1TR 30
     CANVAS_LAYOUT_EX_PATTERN_FLOAT_2_1TL 31
     ）*/
    BROADCAST_VIDEO_PROFILE_480P_1_VERTICAL = 10,//9:16   480x852   25    750
    BROADCAST_VIDEO_PROFILE_540P_1_VERTICAL = 11,//9:16   540x960   25    1150
    BROADCAST_VIDEO_PROFILE_720P_1_VERTICAL = 12,//9:16   720x1280   25    1600
    BROADCAST_VIDEO_PROFILE_1080P_1_VERTICAL = 13,//9:16   1080x1920   25    2200

    BROADCAST_VIDEO_PROFILE_COUNT
};

/**
 @enum 旁路混流布局
 */
typedef NS_ENUM(NSInteger, BroadcastLayout) {
    CANVAS_LAYOUT_PATTERN_GRID_1     = 0,//    一人铺满
    CANVAS_LAYOUT_PATTERN_GRID_2_H   = 1,//    左右两格
    CANVAS_LAYOUT_PATTERN_GRID_3_E   = 2,//    正品字
    CANVAS_LAYOUT_PATTERN_GRID_3_D   = 3,//    倒品字
    CANVAS_LAYOUT_PATTERN_GRID_4_M   = 4,//    2行x2列
    CANVAS_LAYOUT_PATTERN_GRID_5_D   = 5,//    2行，上2下3
    CANVAS_LAYOUT_PATTERN_GRID_6_E   = 6,//    2行x3列
    CANVAS_LAYOUT_PATTERN_GRID_9_E   = 7,//    3行x3列
    CANVAS_LAYOUT_PATTERN_FLOAT_2_1DR    = 8,//     主次悬浮，大屏铺满，小屏悬浮右下角 (小窗宽=画布宽度/5，比例为4:3)
    CANVAS_LAYOUT_PATTERN_FLOAT_2_1DL    = 9,//     主次悬浮，大屏铺满，小屏悬浮左下角 (小窗宽=画布宽度/5，比例为4:3)
    CANVAS_LAYOUT_PATTERN_FLOAT_3_2DL    = 10,//    大屏铺满，2小屏悬浮右上角 (小窗宽=画布宽度/6，比例为4:3)
    CANVAS_LAYOUT_PATTERN_FLOAT_6_5D     = 11,//    主次悬浮，大屏铺满，一行5个悬浮于下面 (小窗宽=画布宽度/5，比例为4:3)
    CANVAS_LAYOUT_PATTERN_FLOAT_6_5T     = 12,//    主次悬浮，大屏铺满，一行5个悬浮于上面 (小窗宽=画布宽度/5，比例为4:3)
    CANVAS_LAYOUT_PATTERN_TILED_5_1T4D   = 13,//    主次平铺，一行4个位于底部
    CANVAS_LAYOUT_PATTERN_TILED_5_1D4T   = 14,//    主次平铺，一行4个位于顶部
    CANVAS_LAYOUT_PATTERN_TILED_5_1L4R   = 15,//    主次平铺，一列4个位于右边
    CANVAS_LAYOUT_PATTERN_TILED_5_1R4L   = 16,//    主次平铺，一列4个位于左边
    CANVAS_LAYOUT_PATTERN_TILED_6_1T5D   = 17,//    主次平铺，一行5个位于底部
    CANVAS_LAYOUT_PATTERN_TILED_6_1D5T   = 18,//    主次平铺，一行5个位于顶部
    CANVAS_LAYOUT_PATTERN_TILED_9_1L8R   = 19,//    主次平铺，右边为（2列x4行=8个块）
    CANVAS_LAYOUT_PATTERN_TILED_9_1R8L   = 20,//    主次平铺，左边为（2列x4行=8个块）
    CANVAS_LAYOUT_PATTERN_TILED_13_1L12R = 21,//    主次平铺，右边为（3列x4行=12个块）
    CANVAS_LAYOUT_PATTERN_TILED_17_1TL16GRID     = 22,//    主次平铺，1V16，主屏在左上角
    CANVAS_LAYOUT_PATTERN_TILED_9_1D8T           = 23,//    主次平铺，主屏在下，8个（2行x4列）在上
    CANVAS_LAYOUT_PATTERN_TILED_13_1TL12GRID     = 24,//    主次平铺，主屏在左上角，其余12个均铺于其他剩余区域
    CANVAS_LAYOUT_PATTERN_TILED_17_1TL16GRID_E   = 25,//    主次平铺，主屏在左上角，其余16个均铺于其他剩余区域
    CANVAS_LAYOUT_PATTERN_CUSTOM                 = 27,//    自定义，当使用坐标布局接口时，请使用此
    CANVAS_LAYOUT_EX_PATTERN_GRID_12_E           = 28,//    3行4列等分布局
    CANVAS_LAYOUT_EX_PATTERN_GRID_16_E           = 29,//    4行4列等分布局
    CANVAS_LAYOUT_EX_PATTERN_FLOAT_2_1TR         = 30,// 主次悬浮，大屏铺满，小屏悬浮右上角 (小窗宽=画布宽度/5，比例为4:3)支持竖版布局，参考PaaS需求： paas pm
    CANVAS_LAYOUT_EX_PATTERN_FLOAT_2_1TL         = 31,// 主次悬浮，大屏铺满，小屏悬浮左上角 (小窗宽=画布宽度/5，比例为4:3)支持竖版布局，参考PaaS需求： paas pm
    CANVAS_ADAPTIVE_LAYOUT_GRID_MODE        = 101,    // 自适应均分模式
    CANVAS_ADAPTIVE_LAYOUT_TILED_MODE       = 102,    // 自适应平铺模式
    CANVAS_ADAPTIVE_LAYOUT_FLOAT_MODE       = 103,    // 自适应悬浮模式
    CANVAS_ADAPTIVE_LAYOUT_TILED_EXT1_MODE  = 104,    // 窗格位于主屏上方，最多16窗格
};

@interface VHBroadCastDef : NSObject
/// 配置旁路混流参数(自适应)
/// @param definition 视频质量参数，推荐使用。即（分辨率+帧率+码率）
/// @param url 推流地址
/// @param layout 布局模式(包括了手动布局和自适应布局)
/// @link http://wiki.vhallops.com/pages/viewpage.action?pageId=195953265#id-%E6%97%81%E8%B7%AF%E6%B7%B7%E6%B5%81%E7%AD%96%E7%95%A5%E4%BC%98%E5%8C%96_SDK%E5%AF%B9%E6%8E%A5-ConfigRoomBroadCast
+ (NSDictionary *)baseConfigRoomBroadCast:(BroadcastDefinition)definition broadCastUrl:(NSString*)url layout:(BroadcastLayout)layout;
@end

#endif /* VHBroadCastDef_h */
