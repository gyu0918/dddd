package com.roulette.roulette.domain;

import jakarta.persistence.*;
import lombok.RequiredArgsConstructor;
import lombok.Setter;

@Entity
@Table(name = "member")
@RequiredArgsConstructor
public class Member {
    @Id
    @Column(name = "member_id")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long memberId;

    @Column(name = "name")
    private String name;

    @Column(name = "email")
    private String email;

    public Member(String name, String email) {
    }

    public Long getMemberId() {
        return memberId;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

}
