ffmpeg -i BadApple.mp4 -s 8x8 -sws_flags neighbor -vf "eq=contrast=1.8" BadApple_scaled.mp4
ffmpeg -r 1 -i BadApple_scaled.mp4 -vf negate -r 1 ./data/BadApple/$BadApple%04d.pbm