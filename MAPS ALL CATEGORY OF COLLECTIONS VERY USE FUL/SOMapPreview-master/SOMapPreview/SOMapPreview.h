//
//  Created by Alex Evers on 3/26/2014.
//  Copyright ©2013-2014 under GNU General Public License (http://www.gnu.org/licenses/gpl.html)
//  Tab Size 8
//

#import <MapKit/MapKit.h>
#import "SOAnimationSequence.h"

@interface SOMapPreview : UIImageView

@property (nonatomic, strong, readonly) UIImage *cachedImage;
@property (nonatomic, strong, readonly) NSString *cachePath;

@property (nonatomic, strong) NSString *cacheDirectory;
@property (nonatomic, strong) UIColor *routeColor;

@property (nonatomic, assign, getter=isGreyscale) BOOL greyscale;
@property (nonatomic, assign, getter=isBordered) BOOL bordered;
@property (nonatomic, assign, getter=isRoundedImage) BOOL roundedImage;
@property (nonatomic, assign) BOOL showsBuildings;
@property (nonatomic, assign) BOOL showsPOI;
@property (nonatomic, assign) MKMapType mapType;

/** Sets the placeholder image that is shown while the map preview is generated
	@param placeholder the loaded UIImage containing the placeholder image
 */
- (void)setPlaceholderImage:(UIImage *)placeholder;

/** Disables the control, removing all images.
	@return BOOL when successful (currently always YES)
 */
- (BOOL)setDisabled;

/** Begins the process of loading the map preview image from file.
	@param polyline the polyline used to create the unique file hash
	@return returns a BOOL stating the operation's success state.
 */
- (BOOL)loadCache:(MKPolyline *)polyline;

/** The starting point for the entire load cascade. Makes use of loadCache: internally.
	@param polyline the polyline to be rendered. This sets the map frame/zoom level as well.
	@return returns a BOOL stating the operation's success state.
 */
- (BOOL)renderPolylineOnMap:(MKPolyline *)polyline;

@end