package hello.domain;


import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;

@Entity
public class MemberDto {
    @Id @GeneratedValue
    @Column(name = "ID")
    private Long id;
    @Column(name = "MEMBER")
    private String member;
    @Column(name = "CONTENT")
    private String content;
    @Column(name = "TITLE")
    private String title;

    public MemberDto(Long id, String member, String content, String title) {
        this.id = id;
        this.member = member;
        this.content = content;
        this.title = title;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getMember() {
        return member;
    }

    public void setMember(String member) {
        this.member = member;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
}
