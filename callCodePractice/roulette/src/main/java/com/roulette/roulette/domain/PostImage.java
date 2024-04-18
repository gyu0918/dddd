package com.roulette.roulette.domain;

import jakarta.persistence.*;

@Entity
public class PostImage {

    @Id
    @Column(name = "post_img_id", nullable = false)
    @GeneratedValue
    private Long postImgId;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "post_id", nullable = false)
    @GeneratedValue
    private Post post;
}
