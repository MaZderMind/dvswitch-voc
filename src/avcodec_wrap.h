// Copyright 2009-2010 Ben Hutchings.
// See the file "COPYING" for licence details.

// Some versions of ffmpeg define an ABS macro, which glib also does.
// The two definitions are equivalent but the duplicate definitions
// provoke a warning.
#undef ABS

// <avcodec.h> may need UINT64_C while <stdint.h> may or may not
// define that for C++.  Therefore, include <stdint.h> here and then
// define UINT64_C if it didn't get defined.
#include <stdint.h>
#ifndef UINT64_C
#define UINT64_C(n) n ## ULL
#endif

// These guards were removed from <avcodec.h>... what were they thinking?
#ifdef __cplusplus
extern "C" {
#endif

#include <avcodec.h>

#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(52, 26, 0)
static inline int
avcodec_decode_video2(AVCodecContext *avctx, AVFrame *picture,
		      int *got_picture_ptr, AVPacket *avpkt)
{
    return avcodec_decode_video(avctx, picture, got_picture_ptr,
				avpkt->data, avpkt->size);
}
#endif

#ifdef __cplusplus
}
#endif

#undef ABS
