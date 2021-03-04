//
//  MAURBackgroundGeolocationFacade.h
//
//  Created by Marian Hello on 04/06/16.
//  Version 2.0.0
//
//  According to apache license
//
//  This is class is using code from christocracy cordova-plugin-background-geolocation plugin
//  https://github.com/christocracy/cordova-plugin-background-geolocation

#ifndef MAURBackgroundGeolocationFacade_h
#define MAURBackgroundGeolocationFacade_h

#import "MAURProviderDelegate.h"
#import "MAURLocation.h"
#import "MAURConfig.h"

@interface MAURBackgroundGeolocationFacade : NSObject

@property (weak, nonatomic) id<MAURProviderDelegate> _Nullable delegate;

- (BOOL) configure:(MAURConfig*_Nullable)config error:(NSError * _Nullable __autoreleasing *_Nullable)outError;
- (BOOL) start:(NSError * _Nullable __autoreleasing *_Nullable)outError;
- (BOOL) stop:(NSError * _Nullable __autoreleasing *_Nullable)outError;
- (BOOL) locationServicesEnabled;
- (CLAuthorizationStatus) authorizationStatus;
- (BOOL) isStarted;
- (void) showAppSettings;
- (void) showLocationSettings;
- (void) switchMode:(MAUROperationalMode)mode;
- (MAURLocation*_Nullable)getStationaryLocation;
- (NSArray<MAURLocation*>*_Nullable) getLocations;
- (NSArray<MAURLocation*>*_Nullable) getValidLocations;
- (BOOL) deleteLocation:(NSNumber*_Nullable)locationId error:(NSError * _Nullable __autoreleasing *_Nullable)outError;
- (BOOL) deleteAllLocations:(NSError * _Nullable __autoreleasing *_Nullable)outError;
- (MAURLocation*_Nullable)getCurrentLocation:(int)timeout maximumAge:(long)maximumAge
                 enableHighAccuracy:(BOOL)enableHighAccuracy
                                       error:(NSError * _Nullable __autoreleasing *_Nullable)outError;
- (MAURConfig*_Nullable) getConfig;
- (NSArray*_Nullable) getLogEntries:(NSInteger)limit;
- (NSArray*_Nullable) getLogEntries:(NSInteger)limit fromLogEntryId:(NSInteger)entryId minLogLevelFromString:(NSString *_Nullable)minLogLevel;
- (void) forceSync;
- (void) onAppTerminate;


/**
 * Sets a transform for each coordinate about to be committed (sent or saved for later sync).
 * You can use this for modifying the coordinates in any way.
 *
 * If the transform returns <code>nil</code>, it will prevent the location from being committed.
 * @param transform - the transform block
 */
+ (void) setLocationTransform:(MAURLocationTransform _Nullable)transform;
+ (MAURLocationTransform _Nullable) locationTransform;

@end

#endif /* MAURBackgroundGeolocationFacade_h */
