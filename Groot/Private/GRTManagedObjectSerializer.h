// GRTManagedObjectSerializer.h
//
// Copyright (c) 2014-2015 Guillermo Gonzalez
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

@interface GRTManagedObjectSerializer : NSObject

/**
 *  Designated initializer for a GRTManagedObjectSerializer.
 *
 *  @param entity The entity description to use during serialization process.
 *
 *  @return An instance of GRTManagedObjectSerializer.
 */
- (instancetype)initWithEntity:(NSEntityDescription *)entity;

/**
 *  Serialize a JSON Array to a collection of NSManagedObjects by providing a source object and the relationship between the source object and the JSON array to serialize.
 *
 *  @param array        The array containing the JSON representation to serialize.
 *  @param sourceObject If assigned, the source object from where the serialization is triggered.
 *  @param relationship If assigned, it is the relationship between the provided source object and JSON array to serialize.
 *  @param context      The context to use to run the serialization process.
 *  @param outError     The error that might occure while processing the serialization process.
 *
 *  @return A collection of NSManagedObject instantiation that conforms to the JSON array serialization.
 */
- (nullable NSArray *)serializeJSONArray:(NSArray *)array
                               forObject:(nullable NSManagedObject *)sourceObject
                          inRelationship:(nullable NSRelationshipDescription *)relationship
                             inContext:(NSManagedObjectContext *)context
                                   error:(NSError *__autoreleasing  __nullable * __nullable)outError;

/**
 *  Serialize a JSON Array to a collection of NSManagedObjects
 *
 *  @param array        The array containing the JSON representation to serialize.
 *  @param context      The context to use to run the serialization process.
 *  @param outError     The error that might occure while processing the serialization process.
 *
 *  @return A collection of NSManagedObject instantiation that conforms to the JSON array serialization.
 */
- (nullable NSArray *)serializeJSONArray:(NSArray *)array
                               inContext:(NSManagedObjectContext *)context
                                   error:(NSError * __nullable * __nullable)error;

@end

NS_ASSUME_NONNULL_END
