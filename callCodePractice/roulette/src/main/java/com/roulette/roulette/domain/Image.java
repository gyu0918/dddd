package com.roulette.roulette.domain;

import jakarta.persistence.*;


import java.time.LocalDateTime;

@Entity
@Table(name = "image")
public class Image {

    @Id
    @Column(name = "img_id", nullable = false)
    @GeneratedValue
    private Long imgId;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "reply_img_id", nullable = false)
    private ReplyImage replyImg;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "post_img_id", nullable = false)
    private PostImage postImg;

    @Column(name = "img_url")
    private String imgUrl;

    @Column(name = "create_time")
    private LocalDateTime createTime;

    @Column(name = "delete_time")
    private LocalDateTime deleteTime;
}
