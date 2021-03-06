// Copyright 2008 Ben Hutchings <ben@decadent.org.uk>.
// See the file "COPYING" for licence details.

#ifndef INC_AUTO_CODEC_HPP
#define INC_AUTO_CODEC_HPP

#include "auto_handle.hpp"

#include "avcodec_wrap.h"

struct auto_codec_closer
{
    void operator()(AVCodecContext * context) const;
};
struct auto_codec_factory
{
    AVCodecContext * operator()() const { return 0; }
};
typedef auto_handle<AVCodecContext *, auto_codec_closer, auto_codec_factory>
auto_codec;

auto_codec auto_codec_open_decoder(AVCodecID);
void auto_codec_open_decoder(const auto_codec &, AVCodecID);
auto_codec auto_codec_open_encoder(AVCodecID);
void auto_codec_open_encoder(const auto_codec &, AVCodecID);

#endif // !INC_AUTO_CODEC_HPP
