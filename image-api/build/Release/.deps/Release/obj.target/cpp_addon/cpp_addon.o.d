cmd_Release/obj.target/cpp_addon/cpp_addon.o := g++ -o Release/obj.target/cpp_addon/cpp_addon.o ../cpp_addon.cpp '-DNODE_GYP_MODULE_NAME=cpp_addon' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DNAPI_DISABLE_CPP_EXCEPTIONS' '-DBUILDING_NODE_EXTENSION' -I/home/dev/.cache/node-gyp/20.11.0/include/node -I/home/dev/.cache/node-gyp/20.11.0/src -I/home/dev/.cache/node-gyp/20.11.0/deps/openssl/config -I/home/dev/.cache/node-gyp/20.11.0/deps/openssl/openssl/include -I/home/dev/.cache/node-gyp/20.11.0/deps/uv/include -I/home/dev/.cache/node-gyp/20.11.0/deps/zlib -I/home/dev/.cache/node-gyp/20.11.0/deps/v8/include -I/mnt/d/Jobs/image-tool/node_modules/node-addon-api -I/usr/include/opencv4  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -frtti -std=c++17 -m64 -O3 -fno-omit-frame-pointer -std=gnu++17 -frtti -std=c++17 -MMD -MF ./Release/.deps/Release/obj.target/cpp_addon/cpp_addon.o.d.raw  -frtti -c
Release/obj.target/cpp_addon/cpp_addon.o: ../cpp_addon.cpp \
 /mnt/d/Jobs/image-tool/node_modules/node-addon-api/napi.h \
 /home/dev/.cache/node-gyp/20.11.0/include/node/node_api.h \
 /home/dev/.cache/node-gyp/20.11.0/include/node/js_native_api.h \
 /home/dev/.cache/node-gyp/20.11.0/include/node/js_native_api_types.h \
 /home/dev/.cache/node-gyp/20.11.0/include/node/node_api_types.h \
 /mnt/d/Jobs/image-tool/node_modules/node-addon-api/napi-inl.h \
 /mnt/d/Jobs/image-tool/node_modules/node-addon-api/napi.h \
 /mnt/d/Jobs/image-tool/node_modules/node-addon-api/napi-inl.deprecated.h \
 /usr/include/opencv4/opencv2/opencv.hpp \
 /usr/include/opencv4/opencv2/opencv_modules.hpp \
 /usr/include/opencv4/opencv2/core.hpp \
 /usr/include/opencv4/opencv2/core/cvdef.h \
 /usr/include/opencv4/opencv2/core/version.hpp \
 /usr/include/opencv4/opencv2/core/hal/interface.h \
 /usr/include/opencv4/opencv2/core/cv_cpu_dispatch.h \
 /usr/include/opencv4/opencv2/core/base.hpp \
 /usr/include/opencv4/opencv2/core/cvstd.hpp \
 /usr/include/opencv4/opencv2/core/cvstd_wrapper.hpp \
 /usr/include/opencv4/opencv2/core/neon_utils.hpp \
 /usr/include/opencv4/opencv2/core/vsx_utils.hpp \
 /usr/include/opencv4/opencv2/core/check.hpp \
 /usr/include/opencv4/opencv2/core/traits.hpp \
 /usr/include/opencv4/opencv2/core/matx.hpp \
 /usr/include/opencv4/opencv2/core/saturate.hpp \
 /usr/include/opencv4/opencv2/core/fast_math.hpp \
 /usr/include/opencv4/opencv2/core/types.hpp \
 /usr/include/opencv4/opencv2/core/mat.hpp \
 /usr/include/opencv4/opencv2/core/bufferpool.hpp \
 /usr/include/opencv4/opencv2/core/mat.inl.hpp \
 /usr/include/opencv4/opencv2/core/persistence.hpp \
 /usr/include/opencv4/opencv2/core/operations.hpp \
 /usr/include/opencv4/opencv2/core/cvstd.inl.hpp \
 /usr/include/opencv4/opencv2/core/utility.hpp \
 /usr/include/opencv4/opencv2/core/optim.hpp \
 /usr/include/opencv4/opencv2/core/ovx.hpp \
 /usr/include/opencv4/opencv2/core/cvdef.h \
 /usr/include/opencv4/opencv2/calib3d.hpp \
 /usr/include/opencv4/opencv2/features2d.hpp \
 /usr/include/opencv4/opencv2/flann/miniflann.hpp \
 /usr/include/opencv4/opencv2/flann/defines.h \
 /usr/include/opencv4/opencv2/flann/config.h \
 /usr/include/opencv4/opencv2/core/affine.hpp \
 /usr/include/opencv4/opencv2/dnn.hpp \
 /usr/include/opencv4/opencv2/dnn/dnn.hpp \
 /usr/include/opencv4/opencv2/core/async.hpp \
 /usr/include/opencv4/opencv2/dnn/../dnn/version.hpp \
 /usr/include/opencv4/opencv2/dnn/dict.hpp \
 /usr/include/opencv4/opencv2/dnn/layer.hpp \
 /usr/include/opencv4/opencv2/dnn/dnn.inl.hpp \
 /usr/include/opencv4/opencv2/dnn/utils/inference_engine.hpp \
 /usr/include/opencv4/opencv2/dnn/utils/../dnn.hpp \
 /usr/include/opencv4/opencv2/flann.hpp \
 /usr/include/opencv4/opencv2/flann/flann_base.hpp \
 /usr/include/opencv4/opencv2/flann/general.h \
 /usr/include/opencv4/opencv2/flann/matrix.h \
 /usr/include/opencv4/opencv2/flann/params.h \
 /usr/include/opencv4/opencv2/flann/any.h \
 /usr/include/opencv4/opencv2/flann/defines.h \
 /usr/include/opencv4/opencv2/flann/saving.h \
 /usr/include/opencv4/opencv2/flann/nn_index.h \
 /usr/include/opencv4/opencv2/flann/result_set.h \
 /usr/include/opencv4/opencv2/flann/all_indices.h \
 /usr/include/opencv4/opencv2/flann/kdtree_index.h \
 /usr/include/opencv4/opencv2/flann/dynamic_bitset.h \
 /usr/include/opencv4/opencv2/flann/dist.h \
 /usr/include/opencv4/opencv2/flann/heap.h \
 /usr/include/opencv4/opencv2/flann/allocator.h \
 /usr/include/opencv4/opencv2/flann/random.h \
 /usr/include/opencv4/opencv2/flann/kdtree_single_index.h \
 /usr/include/opencv4/opencv2/flann/kmeans_index.h \
 /usr/include/opencv4/opencv2/flann/logger.h \
 /usr/include/opencv4/opencv2/flann/composite_index.h \
 /usr/include/opencv4/opencv2/flann/linear_index.h \
 /usr/include/opencv4/opencv2/flann/hierarchical_clustering_index.h \
 /usr/include/opencv4/opencv2/flann/lsh_index.h \
 /usr/include/opencv4/opencv2/flann/lsh_table.h \
 /usr/include/opencv4/opencv2/flann/autotuned_index.h \
 /usr/include/opencv4/opencv2/flann/ground_truth.h \
 /usr/include/opencv4/opencv2/flann/index_testing.h \
 /usr/include/opencv4/opencv2/flann/timer.h \
 /usr/include/opencv4/opencv2/flann/sampling.h \
 /usr/include/opencv4/opencv2/highgui.hpp \
 /usr/include/opencv4/opencv2/imgcodecs.hpp \
 /usr/include/opencv4/opencv2/videoio.hpp \
 /usr/include/opencv4/opencv2/imgproc.hpp \
 /usr/include/opencv4/opencv2/./imgproc/segmentation.hpp \
 /usr/include/opencv4/opencv2/ml.hpp \
 /usr/include/opencv4/opencv2/ml/ml.inl.hpp \
 /usr/include/opencv4/opencv2/objdetect.hpp \
 /usr/include/opencv4/opencv2/objdetect/detection_based_tracker.hpp \
 /usr/include/opencv4/opencv2/objdetect/face.hpp \
 /usr/include/opencv4/opencv2/photo.hpp \
 /usr/include/opencv4/opencv2/stitching.hpp \
 /usr/include/opencv4/opencv2/stitching/warpers.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/warpers.hpp \
 /usr/include/opencv4/opencv2/core/cuda.hpp \
 /usr/include/opencv4/opencv2/core/cuda_types.hpp \
 /usr/include/opencv4/opencv2/core/cuda.inl.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/warpers_inl.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/warpers.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/matchers.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/motion_estimators.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/matchers.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/util.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/util_inl.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/camera.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/exposure_compensate.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/seam_finders.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/blenders.hpp \
 /usr/include/opencv4/opencv2/stitching/detail/camera.hpp \
 /usr/include/opencv4/opencv2/video.hpp \
 /usr/include/opencv4/opencv2/video/tracking.hpp \
 /usr/include/opencv4/opencv2/video/background_segm.hpp
../cpp_addon.cpp:
/mnt/d/Jobs/image-tool/node_modules/node-addon-api/napi.h:
/home/dev/.cache/node-gyp/20.11.0/include/node/node_api.h:
/home/dev/.cache/node-gyp/20.11.0/include/node/js_native_api.h:
/home/dev/.cache/node-gyp/20.11.0/include/node/js_native_api_types.h:
/home/dev/.cache/node-gyp/20.11.0/include/node/node_api_types.h:
/mnt/d/Jobs/image-tool/node_modules/node-addon-api/napi-inl.h:
/mnt/d/Jobs/image-tool/node_modules/node-addon-api/napi.h:
/mnt/d/Jobs/image-tool/node_modules/node-addon-api/napi-inl.deprecated.h:
/usr/include/opencv4/opencv2/opencv.hpp:
/usr/include/opencv4/opencv2/opencv_modules.hpp:
/usr/include/opencv4/opencv2/core.hpp:
/usr/include/opencv4/opencv2/core/cvdef.h:
/usr/include/opencv4/opencv2/core/version.hpp:
/usr/include/opencv4/opencv2/core/hal/interface.h:
/usr/include/opencv4/opencv2/core/cv_cpu_dispatch.h:
/usr/include/opencv4/opencv2/core/base.hpp:
/usr/include/opencv4/opencv2/core/cvstd.hpp:
/usr/include/opencv4/opencv2/core/cvstd_wrapper.hpp:
/usr/include/opencv4/opencv2/core/neon_utils.hpp:
/usr/include/opencv4/opencv2/core/vsx_utils.hpp:
/usr/include/opencv4/opencv2/core/check.hpp:
/usr/include/opencv4/opencv2/core/traits.hpp:
/usr/include/opencv4/opencv2/core/matx.hpp:
/usr/include/opencv4/opencv2/core/saturate.hpp:
/usr/include/opencv4/opencv2/core/fast_math.hpp:
/usr/include/opencv4/opencv2/core/types.hpp:
/usr/include/opencv4/opencv2/core/mat.hpp:
/usr/include/opencv4/opencv2/core/bufferpool.hpp:
/usr/include/opencv4/opencv2/core/mat.inl.hpp:
/usr/include/opencv4/opencv2/core/persistence.hpp:
/usr/include/opencv4/opencv2/core/operations.hpp:
/usr/include/opencv4/opencv2/core/cvstd.inl.hpp:
/usr/include/opencv4/opencv2/core/utility.hpp:
/usr/include/opencv4/opencv2/core/optim.hpp:
/usr/include/opencv4/opencv2/core/ovx.hpp:
/usr/include/opencv4/opencv2/core/cvdef.h:
/usr/include/opencv4/opencv2/calib3d.hpp:
/usr/include/opencv4/opencv2/features2d.hpp:
/usr/include/opencv4/opencv2/flann/miniflann.hpp:
/usr/include/opencv4/opencv2/flann/defines.h:
/usr/include/opencv4/opencv2/flann/config.h:
/usr/include/opencv4/opencv2/core/affine.hpp:
/usr/include/opencv4/opencv2/dnn.hpp:
/usr/include/opencv4/opencv2/dnn/dnn.hpp:
/usr/include/opencv4/opencv2/core/async.hpp:
/usr/include/opencv4/opencv2/dnn/../dnn/version.hpp:
/usr/include/opencv4/opencv2/dnn/dict.hpp:
/usr/include/opencv4/opencv2/dnn/layer.hpp:
/usr/include/opencv4/opencv2/dnn/dnn.inl.hpp:
/usr/include/opencv4/opencv2/dnn/utils/inference_engine.hpp:
/usr/include/opencv4/opencv2/dnn/utils/../dnn.hpp:
/usr/include/opencv4/opencv2/flann.hpp:
/usr/include/opencv4/opencv2/flann/flann_base.hpp:
/usr/include/opencv4/opencv2/flann/general.h:
/usr/include/opencv4/opencv2/flann/matrix.h:
/usr/include/opencv4/opencv2/flann/params.h:
/usr/include/opencv4/opencv2/flann/any.h:
/usr/include/opencv4/opencv2/flann/defines.h:
/usr/include/opencv4/opencv2/flann/saving.h:
/usr/include/opencv4/opencv2/flann/nn_index.h:
/usr/include/opencv4/opencv2/flann/result_set.h:
/usr/include/opencv4/opencv2/flann/all_indices.h:
/usr/include/opencv4/opencv2/flann/kdtree_index.h:
/usr/include/opencv4/opencv2/flann/dynamic_bitset.h:
/usr/include/opencv4/opencv2/flann/dist.h:
/usr/include/opencv4/opencv2/flann/heap.h:
/usr/include/opencv4/opencv2/flann/allocator.h:
/usr/include/opencv4/opencv2/flann/random.h:
/usr/include/opencv4/opencv2/flann/kdtree_single_index.h:
/usr/include/opencv4/opencv2/flann/kmeans_index.h:
/usr/include/opencv4/opencv2/flann/logger.h:
/usr/include/opencv4/opencv2/flann/composite_index.h:
/usr/include/opencv4/opencv2/flann/linear_index.h:
/usr/include/opencv4/opencv2/flann/hierarchical_clustering_index.h:
/usr/include/opencv4/opencv2/flann/lsh_index.h:
/usr/include/opencv4/opencv2/flann/lsh_table.h:
/usr/include/opencv4/opencv2/flann/autotuned_index.h:
/usr/include/opencv4/opencv2/flann/ground_truth.h:
/usr/include/opencv4/opencv2/flann/index_testing.h:
/usr/include/opencv4/opencv2/flann/timer.h:
/usr/include/opencv4/opencv2/flann/sampling.h:
/usr/include/opencv4/opencv2/highgui.hpp:
/usr/include/opencv4/opencv2/imgcodecs.hpp:
/usr/include/opencv4/opencv2/videoio.hpp:
/usr/include/opencv4/opencv2/imgproc.hpp:
/usr/include/opencv4/opencv2/./imgproc/segmentation.hpp:
/usr/include/opencv4/opencv2/ml.hpp:
/usr/include/opencv4/opencv2/ml/ml.inl.hpp:
/usr/include/opencv4/opencv2/objdetect.hpp:
/usr/include/opencv4/opencv2/objdetect/detection_based_tracker.hpp:
/usr/include/opencv4/opencv2/objdetect/face.hpp:
/usr/include/opencv4/opencv2/photo.hpp:
/usr/include/opencv4/opencv2/stitching.hpp:
/usr/include/opencv4/opencv2/stitching/warpers.hpp:
/usr/include/opencv4/opencv2/stitching/detail/warpers.hpp:
/usr/include/opencv4/opencv2/core/cuda.hpp:
/usr/include/opencv4/opencv2/core/cuda_types.hpp:
/usr/include/opencv4/opencv2/core/cuda.inl.hpp:
/usr/include/opencv4/opencv2/stitching/detail/warpers_inl.hpp:
/usr/include/opencv4/opencv2/stitching/detail/warpers.hpp:
/usr/include/opencv4/opencv2/stitching/detail/matchers.hpp:
/usr/include/opencv4/opencv2/stitching/detail/motion_estimators.hpp:
/usr/include/opencv4/opencv2/stitching/detail/matchers.hpp:
/usr/include/opencv4/opencv2/stitching/detail/util.hpp:
/usr/include/opencv4/opencv2/stitching/detail/util_inl.hpp:
/usr/include/opencv4/opencv2/stitching/detail/camera.hpp:
/usr/include/opencv4/opencv2/stitching/detail/exposure_compensate.hpp:
/usr/include/opencv4/opencv2/stitching/detail/seam_finders.hpp:
/usr/include/opencv4/opencv2/stitching/detail/blenders.hpp:
/usr/include/opencv4/opencv2/stitching/detail/camera.hpp:
/usr/include/opencv4/opencv2/video.hpp:
/usr/include/opencv4/opencv2/video/tracking.hpp:
/usr/include/opencv4/opencv2/video/background_segm.hpp:
